#include <bits/stdc++.h>

using namespace std;
const int c=500005;
long long avg, po[c], inv[c], mod=1e9+7, ans;
long long n, m, k, szint[c], fel[c];
long long spec=0;
vector<int> sz[c], kor, cs[c];
vector<pair<int, int> > kor2;
bool v[c];
void dfs(int a) {
    //cout << "dfs " << a << "\n";
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        } else if (szint[a]-szint[x]>1) {
            int h=szint[a]-szint[x]+1;
            kor.push_back(h);
            //cout << "kor " << h << "\n";
            int pos=a;
            int cnt=0;
            while (szint[pos]>=szint[x]) {
                //cout << "kor " << pos << "\n";
                cs[pos].push_back(h);
                int si=sz[pos].size();
                cnt+=si-2;
                pos=fel[pos];
            }
            kor2.push_back({h, cnt});

        }
    }
}
long long dif() {
    return (ans-spec+mod)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n==1) {
        cout << (mod+1)/4 << "\n";
        return 0;
    }
    po[0]=1, inv[0]=1, inv[1]=(mod+1)/2;
    for (int i=1; i<=m+2; i++) {
        po[i]=po[i-1]*2%mod;
        if (i>1) {
            inv[i]=inv[i-1]*inv[1]%mod;
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }

    szint[1]=1;
    dfs(1);
    avg=n*po[n-1]%mod-m*po[n-2]%mod+mod;
    for (auto x:kor) {
        avg+=po[n-x];
    }
    avg%=mod;
    avg+=0;
    //cout << "atlag " << avg << "\n";
    avg=(avg*inv[n])%mod;
    //cout << "vege " << avg << "\n";






    // csucs*csucs
    spec=ans;
    ans+=n*po[n-1]%mod+n*(n-1)%mod*po[n-2]%mod;
    //cout << "csucs*csucs: " << dif() << "\n";


    // avg*avg
    spec=ans;
    ans+=avg*avg%mod*po[n]%mod;
    ans%=mod;
    //cout << "avg*avg: " << dif() << "\n";


    // -2*avg*csucs
    spec=ans;
    ans-=2*avg*n%mod*po[n-1]%mod;
    //cout << "-2*avg*csucs: " << dif()-mod << "\n";

    spec=ans;
    // el*el
    long long cnt=0;
    for (int i=1; i<=n; i++) {
        int si=sz[i].size();
        cnt+=si*(si-1);
    }
    ans+=m*po[n-2];
    //cout << "ugyanaz " << m*po[n-2] << "\n";
    ans%=mod;
    if (cnt) {
        ans+=cnt*po[n-3];
        ans%=mod;
        //cout << "szomszedos " << cnt*po[n-3] << "\n";
    }
    if (cnt+m<m*m) {
        ans+=(m*m-m-cnt)%mod*po[n-4]%mod;
        //cout << "tavoli " << (m*m-m-cnt)*po[n-4] << "\n";
        ans%=mod;
    }
    //cout << "el*el: " << dif() << "\n";

    // -2*csucs*el
    spec=ans;
    ans-=2*m*2*po[n-2]%mod;
    if (n>=3) {
        ans-=2*m*(n-2)%mod*po[n-3]%mod;
    }
    //cout << "-2*csucs*el: " << dif()-mod << "\n";

    // +2*avg*el
    spec=ans;
    ans+=2*avg*m%mod*po[n-2]%mod;
    //cout << "2*avg*el: " << dif() << "\n";





    // kor*kor;
    spec=ans;
    long long s=0;
    for (auto x:kor) {
        s+=po[n-x];
    }
    s%=mod;

    for (auto x:kor) {
        ans+=po[n-x];
        ans+=(s-po[n-x]+mod)*inv[x]%mod;
    }
    //cout << "resz " << dif() << "\n";
    for (int i=1; i<=n; i++) {
        long long s2=0;
        for (auto x:cs[i]) {
            //cout << "kor " << i << " " << x << "\n";
            s2+=po[n-x];
        }
        s2%=mod;
        for (auto x:cs[i]) {
            ans+=(s2-po[n-x]+mod)*inv[x]%mod;
        }
    }
    //cout << "kor*kor: " << dif() << "\n";

    spec=ans;

    // +2*csucs*kor
    for (auto x:kor) {
        ans+=2*po[n-x]*x%mod;
        if (n-x>0) {
            ans+=2*(n-x)*po[n-x-1]%mod;
        }
    }
    //cout << "2*csucs*kor: " << dif() << "\n";

    // -2*avg*kor
    spec=ans;
    for (auto x:kor) {
        ans-=2*avg*po[n-x]%mod;
    }
    //cout << "2*avg*kor " << dif()-mod << "\n";


    // -2*el*kor;
    spec=ans;
    for (auto x:kor2) {
        long long fi=x.first, se=x.second;
        ans-=2*po[n-fi]*fi%mod;
        if (se) {
            ans-=2*po[n-fi-1]*se%mod;
        }
        if (m-fi-se) {
            ans-=2*po[n-fi-2]*(m-fi-se)%mod;
        }
    }
    //cout << "-2*el*kor: " << dif()-mod << "\n";


    //cout << "vege " << ans%mod << "\n";


    ans+=mod*mod;
    ans%=mod;


    cout << ans*inv[n]%mod << "\n";
    return 0;
}
/*
5 6
1 2
2 3
1 3
3 4
4 5
3 5
*/
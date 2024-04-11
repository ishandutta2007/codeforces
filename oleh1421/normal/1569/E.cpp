#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
//#define int ll
using namespace std;
const int N=33;
const ll mod=998244353;
ll pw[N];
int k;
ll A,h;
int p[N];
ll val[N];
map<ll,int>mp;
void solve(){
    cin>>k;
    cin>>A>>h;
//    if (k==1){
//        if (h==A){
//            cout<<1<<endl;
//        } else {
//            cout<<-1<<endl;
//        }
//        return;
//    }

    pw[0]=1;
    for (int i=1;i<=(1<<k);i++){
        pw[i]=(pw[i-1]*A)%mod;
    }
    for (int i=1;i<=(1<<(k-1));i++){
        int cnt=0;
        while (i%(1<<(cnt+1))==0) cnt++;
        if (cnt==k-1) val[i]=pw[1]-pw[(1<<(k-1))+1]+mod;
        else val[i]=pw[(1<<(k-cnt-2))+1]-pw[(1<<(k-1))+1]+mod;
    }
    for (int i=0;i<(1<<(1<<(k-1)));i++){
        ll sum=0ll;
        for (int j=0;j<(1<<(k-1));j++){
            if (i&(1<<j)) sum+=val[j+1];
        }
        sum%=mod;
        mp[sum]=i;
//        cout<<sum<<endl;
    }
    int games=(1<<(k-1))-1;
    int Mask=-1;
    for (int mask=0;mask<(1<<games);mask++){
        vector<int>v;
        for (int i=1;i<=(1<<(k-1));i++){
            v.push_back(i);
        }
        int ind=0;
        for (int depth=k-2;depth>=0;depth--){
            vector<int>u;
            for (int i=1;i<v.size();i+=2){
                if (mask&(1<<ind)) u.push_back(v[i]),p[v[i-1]]=(1<<depth)+1;
                else u.push_back(v[i-1]),p[v[i]]=(1<<depth)+1;
                ind++;
            }
            v=u;
        }
        p[v[0]]=1;
        ll h1=0ll;
        for (int i=1;i<=(1<<(k-1));i++){
            h1+=pw[p[i]]*(i*2ll-1ll);
            h1+=pw[(1<<(k-1))+1]*(i*2ll);
        }
        h1%=mod;
        ll need=(h-h1+mod)%mod;
        if (mp.find(need)!=mp.end()){
            Mask=mask;
            break;
        }
    }
    if (Mask==-1){
        cout<<-1<<endl;
        return;
    }
    for (int mask=Mask;mask<=Mask;mask++){
        for (int cn=0;cn<(1<<(1<<(k-1)));cn++){
            vector<int>v;
            for (int i=1;i<=(1<<(k-1));i++){
                if (cn&(1<<(i-1))) v.push_back(i*2),p[i*2-1]=(1<<(k-1))+1;
                else v.push_back(i*2-1),p[(i*2)]=(1<<(k-1))+1;
            }
            int ind=0;
            for (int depth=k-2;depth>=0;depth--){
                vector<int>u;
                for (int i=1;i<v.size();i+=2){
                    if (mask&(1<<ind)) u.push_back(v[i]),p[v[i-1]]=(1<<depth)+1;
                    else u.push_back(v[i-1]),p[v[i]]=(1<<depth)+1;
                    ind++;
                }
                v=u;
            }
            p[v[0]]=1;
            ll h1=0ll;
            for (int i=1;i<=(1<<k);i++){
                h1+=pw[p[i]]*(i*1ll);
            }
            h1%=mod;
            if (h1==h){
                for (int i=1;i<=(1<<k);i++) cout<<p[i]<<" ";
                cout<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;





}
int32_t main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt=1;
    while (tt--){
        solve();
    }
    return 0;
}
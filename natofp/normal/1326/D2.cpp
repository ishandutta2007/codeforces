#include <bits/stdc++.h>
#define ll long long int
#define pb push_back

using namespace std;
const int mod=1e9+7;
const int mod2=998244353;
int p=31;
int p2=37;
const int nax=1e6+5;
vector<ll> hasz1(nax,0);
vector<ll> hasz2(nax,0);
vector<ll> hasz3(nax,0);
vector<ll> hasz4(nax,0);
ll pot[nax];
ll pot2[nax];


vector<int> d1(nax,0);
vector<int> d2(nax,0);

string s;


pair<ll,ll> daj(int lo,int hi,int n,int nr)
{
    if(lo>hi) return {0,0};
    ll res=0;
    ll res2=0;
    if(nr==1)
    {
        res=hasz1[hi];
        if(lo>0) res-=hasz1[lo-1];
        if(res<0) res+=mod;
        res*=pot[n-hi-1];
        res%=mod;
        res2=hasz3[hi];
        if(lo>0) res2-=hasz3[lo-1];
        if(res2<0) res2+=mod2;
        res2*=pot2[n-hi-1];
        res2%=mod2;
        return {res,res2};
    }
    else
    {
        res=hasz2[hi];
        if(lo>0) res-=hasz2[lo-1];
        if(res<0) res+=mod;
        res*=pot[n-hi-1];
        res%=mod;
        res2=hasz4[hi];
        if(lo>0) res2-=hasz4[lo-1];
        if(res2<0) res2+=mod2;
        res2*=pot2[n-hi-1];
        res2%=mod2;
        return {res,res2};
    }
}

bool ok(int lo,int hi,int n)
{
    int len=(hi-lo+1);
    len/=2;
    pair<int,int> val1=daj(lo,lo+len-1,n,1);
    pair<int,int> val2=daj(n-1-hi,n-1-hi+len-1,n,2);
    if(val1==val2) return true;
    return false;
}



void solve()
{
    cin>>s;
    ll akt=1;
    ll akt2=1;
    int n=s.length();
    d1.resize(n,0);
    d2.resize(n,0);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
        k++;
    }
    d1[i] = k--;
    if (i + k > r) {
        l = i - k;
        r = i + k;
    }
    }
    for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
        k++;
    }
    d2[i] = k--;
    if (i + k > r) {
        l = i - k - 1;
        r = i + k ;
    }
}
    for(int i=0;i<=n;i++)
    {
        hasz1[i]=0;
        hasz2[i]=0;
        hasz3[i]=0;
        hasz4[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        hasz1[i]=(s[i]-'a'+1)*akt;
        akt*=p;
        akt%=mod;
        if(i>0) hasz1[i]+=hasz1[i-1];
        hasz1[i]%=mod;
        hasz3[i]=(s[i]-'a'+1)*akt2;
        akt2*=p2;
        akt2%=mod2;
        if(i>0) hasz3[i]+=hasz3[i-1];
        hasz3[i]%=mod2;
    }
    string t="";
    for(int i=n-1;i>=0;i--) t+=s[i];
    akt=1;
    akt2=1;
    for(int i=0;i<n;i++)
    {
        hasz2[i]=(t[i]-'a'+1)*akt;
        akt*=p;
        akt%=mod;
        if(i>0) hasz2[i]+=hasz2[i-1];
        hasz2[i]%=mod;
        hasz4[i]=(t[i]-'a'+1)*akt2;
        akt2*=p2;
        akt2%=mod2;
        if(i>0) hasz4[i]+=hasz4[i-1];
        hasz4[i]%=mod2;
    }
    int ans1,ans2;
    ans1=ans2=0;
    for(int i=0;i<n;i++)
    {
        int p1=d1[i];
        int len=p1*2-1;
        int pocz=i-p1+1;
        int kon=i+p1-1;
        int dlug=min(pocz,n-1-kon);
        //cout<<len<<" "<<dlug<<endl;
        dlug=max(dlug,0);
        pair<int,int> val1=daj(0,dlug-1,n,1);
        pair<int,int> val2=daj(0,dlug-1,n,2);
        if(val1!=val2) continue;
        if(dlug*2+len>ans1+ans2)
        {
            if(dlug*2+len==n) { ans1=n; ans2=0;}
            else
            {

                if(pocz<n-1-kon)
                {
                    ans1=dlug+len;
                    ans2=dlug;
                }
                else
                {
                    ans1=dlug;
                    ans2=dlug+len;
                }
            }
        }

    }
    for(int i=1;i<n;i++)
    {
        int p1=d2[i];
        int len=p1*2;
        int pocz=i-p1;
        int kon=i+p1-1;
        int dlug=min(pocz,n-1-kon);
        //cout<<len<<" "<<dlug<<endl;
        dlug=max(dlug,0);
        pair<int,int> val1=daj(0,dlug-1,n,1);
        pair<int,int> val2=daj(0,dlug-1,n,2);
        if(val1!=val2) continue;
        if(dlug*2+len>ans1+ans2)
        {
            if(dlug*2+len==n) { ans1=n; ans2=0;}
            else
            {

                if(pocz<n-1-kon)
                {
                    ans1=dlug+len;
                    ans2=dlug;
                }
                else
                {
                    ans1=dlug;
                    ans2=dlug+len;
                }
            }
        }

    }
    //cout<<ans1<<" "<<ans2<<endl;
    for(int i=0;i<ans1;i++) cout<<s[i];
    for(int j=0;j<ans2;j++) cout<<s[n-ans2+j];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    pot[0]=1;
    pot2[0]=1;
    for(int i=1;i<nax;i++)
    {
        pot[i]=pot[i-1]*p;
        pot[i]%=mod;
        pot2[i]=pot2[i-1]*p2;
        pot2[i]%=mod2;
    }
    int t; cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
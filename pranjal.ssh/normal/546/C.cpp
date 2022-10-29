#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(x,c) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    string s1,s2;
    int k1,k2;
    cin>>k1;
    int x;
    s1="";
    FOR(i,1,k1)
    {
        cin>>x;--x;char y='0'+x;s1=s1+y;
    }
    cin>>k2;s2="";
    FOR(i,1,k2){cin>>x;--x;char y='0'+x;s2=s2+y;}
    int cnt=0;
    set<pair<string,string> >s;
    while(1)
    {
        if(fpresent(mp(s1,s2),s)||fpresent(mp(s2,s1),s))
        {cout<<"-1";break;}
        s.insert(mp(s1,s2));
        if(s1.length()==0)
        {cout<<cnt<<" 2";break;}
        if(s2.length()==0){cout<<cnt<<" 1";break;}
        ++cnt;
        if(s1[0]>s2[0])
        {
            char x=s1[0];char y=s2[0];
            s1=s1.substr(1,s1.length()-1);s2=s2.substr(1,s2.length()-1);
            s1=(s1+y)+x;
        }
    else if(s2[0]>s1[0])
        {
            char x=s1[0];char y=s2[0];
            s1=s1.substr(1,s1.length()-1);s2=s2.substr(1,s2.length()-1);
            s2=(s2+x)+y;
        }
    //  cout<<s1<<" "<<s2<<"\n";
    }
    return 0;
}
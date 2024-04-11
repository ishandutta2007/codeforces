#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define X first
#define Y second
#define FOR(i,a,b) for(int i=a;i<=b;++i)

int f[26];
int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
   
    tr(s,i)
    {
        if(*i>='A'&&*i<='Z')
        *i=*i+32;
        f[*i-'a']++;
    }
    FOR(i,0,25)
    {
        if(!f[i]){cout<<"NO";return 0;}
    }
    cout<<"YES";
    return 0;
}
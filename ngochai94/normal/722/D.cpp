#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define off 250555

int n,val;
set<int> s;

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;
    while(n--)
    {
        cin >> val;
        s.insert(val);
    }
    while(1)
    {
        auto it = s.end();
        it--;
        val = *it;
        while(val&&s.count(val)) val/=2;
        if(!val)
        {
            for(int i:s) cout << i << ' ';
            return 0;
        }
        s.erase(it);
        s.insert(val);
    }
}
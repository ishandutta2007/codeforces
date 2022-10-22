#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;++i)
#define int int64_t
using namespace std;

int32_t main()
{
    int tmp,sit,t,x,y,a,b,count; cin>>t;
    loop(i,0,t){
        count=0;
        cin>>x>>y>>a>>b;
        sit=y*x;
        a=abs(a); b=abs(b);
        if(b>=2*a||sit<=0){
            count+=x+y;
            count*=a;
        }
        else{
            if(x<y){ tmp=x; x=y; y=tmp; }
            while(y>0){
                count+=b; x--; y--;
            }
            count+=x*a;
        }
        cout<<count<<endl;
    }

    return 0;
}
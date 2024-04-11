// Thanks to robs77 for this template
/***********HEADER***************/
#include<bits/stdc++.h>
using namespace std;
/***********MACROS***************/
//#define int long long
#define inf 100000000000000000 
#define ll  long long 
#define f  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
/*********VARIABLE****************/

typedef pair<ll,ll> ii;
struct sol {ll val; ll lis;};
/******************************/
map<int,int>clrr;
queue<int>q;
int t;
int n,m;
int a,b;
/*********FUNCTIONS**************/

/***********MAIN**************/

int main()
{
	f
	cin>>t;
	while(t--){
 
        cin>>n>>m;
        vector<int>v[n+10];
 
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        
        int one=0;
        int two=0;
 
        q.push(1);
        clrr[1]=1;
        one++;
 
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i=0;i<v[x].size();i++){
                if(clrr[v[x][i]]==0){
                    q.push(v[x][i]);
                    if(clrr[x]==1){
                        two++;
                        clrr[v[x][i]]=2;
                    }
                    else{
                        one++;
                        clrr[v[x][i]]=1;
                    }
                }
            }
        }
        cout<<min(one,two)<<endl;
        for(int i=1;i<=n;i++){
            if(clrr[i]==1 && one<=two)cout<<i<<" ";
            else if(clrr[i]==2 && two<one)cout<<i<<" ";
        }
        cout<<endl;
        clrr.clear();
    }
}
/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
//---------END-------//
vector<int> gt[500001],fl[500001];
int mk[500001];
int par[500001];
int resp[500001];
int resq[500001];
int n,m,i,j,k,t,t1,u,v,a,b,t2,t3;
int star[500001];
int ind[500001];
vector<int> lis[500001],safe;
void dfs(int x, int d)
{
	mk[x]=d;
	for (auto g : gt[x]) if (!mk[g])
	{
		fl[x].push_back(g);
      	fl[g].push_back(x);
		par[g]=x;
		dfs(g,d+1);
	}
}
int main()
{
	fio;
	cin>>t2;
	for (t3=0;t3<t2;t3++)
	{
		cin>>n>>m;
		safe.clear();
		for (i=1;i<=n;i++)
		{
			gt[i].clear();
			fl[i].clear();
			mk[i]=0;
			resp[i]=0;
			resq[i]=0;
			star[i]=0;
			lis[i].clear();
			ind[i]=0;
		}
		for (i=1;i<=m;i++)
		{
			cin>>u>>v;
			gt[u].push_back(v);
			gt[v].push_back(u);
		}
		t=0;
		for (i=1;i<=n;i++)
		if (gt[i].size()==n-1)
		{
			t++;
			mk[i]=-1;
			resp[i]=t;
			resq[i]=t;
		}
		else
		{
			safe.push_back(i);
			ind[i]=safe.size();
		}
		sort(safe.begin(),safe.end());
		for (i=1;i<=n;i++)
		for (int g : gt[i]) if (mk[g]!=-1)
		{
			fl[i].push_back(g);
		}
		for (i=1;i<=n;i++)
		{
			gt[i]=fl[i];
			fl[i].clear();
		}
      	
      
		for (i=1;i<=n;i++) if (mk[i]>=0)
        {
  //        cout<<i<<' '<<ind[i]<<":\n";
    //      for (auto g : gt[i]) cout<<g<<' '; cout<<endl;
        }
      //	cout<<"safe:\n";
      //	for (auto g : safe) cout<<g<<' '; cout<<endl;
		for (i=1;i<=n;i++) if (!mk[i])
		{
			sort(gt[i].begin(),gt[i].end());
		v=0;
          for (j=0;j<gt[i].size();j++)
			{
				u=j;
				if (gt[i][j]>=i) u++;
				if (ind[gt[i][j]]>u+1)
				{
               //   cout<<"YASS\n";
                  v=1;
                 // 	cout<<i<<' '<<j<<' '<<gt[i][j]<<endl;
					if (ind[i]-ind[gt[i][j]]+1) gt[i]={safe[ind[gt[i][j]]-2]};
                  else gt[i]={safe[ind[gt[i][j]]-3]};
                //  cout<<gt[i][0]<<endl;
					break;
				}
			}
          
          if (!v)
          {
              	if (ind[i]==safe.size()) gt[i]={safe[safe.size()-2]};
              else gt[i]={safe[safe.size()-1]};
          }
          
       //   cout<<i<<' '<<gt[i][0]<<endl;
		}
      
      	for (i=1;i<=n;i++) if (!mk[i]) gt[gt[i][0]].push_back(i);
      
		for (i=1;i<=n;i++) if (!mk[i])
		dfs(i,1);
      
		for (i=1;i<=n;i++) if (mk[i]>=1)
        {
      //    cout<<i<<":\n";
      //    for (auto g : fl[i]) cout<<g<<' '; cout<<endl;
        }
      
		t1=0;
		for (i=1;i<=n;i++) if ((mk[i]>=0)and(star[i]==0))
		{
			t1++;
			u=0;
          	for (auto g : fl[i]) if (star[g]<0) {
            star[i]=-star[g];
              lis[star[i]][1]++;
              u=1;
              break;
            }
          if (u) continue;
			for (auto g : fl[i]) if (star[g]==0) {star[g]=t1; u++;}
			if (u)
			{
				star[i]=-t1;
				lis[t1]={i,u};
			}
			else
			{
				u=fl[i][0];
				if (lis[star[u]][1]>1)
				{
					lis[star[u]][1]--;
					star[u]=t1;
					star[i]=-t1;
					lis[t1]={i,1};
				}
				else
				{
					v=lis[star[u]][0];
					lis[star[u]]={};
					star[u]=-t1;
					star[i]=t1;
					star[v]=t1;
					lis[t1]={u,2};
				}
			}
      //    for (j=1;j<=n;j++) cout<<star[j]<<' '; cout<<endl;
		}
      	for (i=1;i<=t1;i++) if (lis[i].size()) lis[i].pop_back();
		for (i=1;i<=n;i++) if (star[i]>0)
		{
			lis[star[i]].push_back(i);
		}
      	
		for (i=1;i<=t1;i++) if (lis[i].size())
		{
          //	for (j=0;j<lis[i].size();j++) cout<<lis[i][j]<<' '; cout<<endl;
			resp[lis[i][0]]=t+1;
			resq[lis[i][0]]=t+lis[i].size();
			for (j=1;j<lis[i].size();j++)
			{
				resp[lis[i][j]]=t+j+1;
				resq[lis[i][j]]=t+j;
			}
			t+=lis[i].size();
		}
      
		for (i=1;i<=n;i++) cout<<resp[i]<<' '; cout<<endl;
		for (i=1;i<=n;i++) cout<<resq[i]<<' '; cout<<endl;
	//	cout<<t2<<endl;
	}
}
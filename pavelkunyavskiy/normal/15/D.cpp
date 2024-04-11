#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <stack>
#define mp make_pair
#define pb push_back                     
#define int64 long long
#define ld long double  
#define setval(a,v) memset(a,v,sizeof(a))
#define pii pair<int,int>
using namespace std;

int64 sum[1010][1010];
int64 sum2[1010][1010];
int mv[1010][1010];
int mv2[1010][1010];
int64 v[1010][1010];
int h[1010][1010];

int n,m,a,b;

void gensum(){
    setval(sum,0);
    for (int i=0;i<n;i++)
        for (int j=m-1;j>=0;j--){
            sum[i][j]=sum[i][j+1]+h[i][j];
            if (j+a<m)
                sum[i][j]-=h[i][j+a];
        }
    for (int j=0;j<m;j++)
        for (int i=n-1;i>=0;--i)
            {
                sum2[i][j]=sum2[i+1][j]+sum[i][j];
                if (i+b<n)
                    sum2[i][j]-=sum[i+b][j];
            }
}

void genmin(){
    for (int i=0;i<n;i++){
        multiset<int> s;
        s.clear();
        for (int j=m-1;j>=0;j--){
                s.insert(h[i][j]);
                if (j+a<m)
                    s.erase(s.find(h[i][j+a]));
                mv[i][j]=*s.begin();
        }           
    }
    
    for (int j=0;j<m;j++){
        multiset<int> s;
        s.clear();
        for (int i=n-1;i>=0;i--){
                s.insert(mv[i][j]);
                if (i+b<n)
                    s.erase(s.find(mv[i+b][j]));
                mv2[i][j]=*s.begin();
        }       
    }
}

void genv(){
    gensum();
    genmin();
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
                v[i][j]=sum2[i][j]-mv2[i][j]*1ll*a*b;               

}

bool used[1010][1010];

void use(int x,int y){
    for (int i=max(x-b+1,0);i<min(x+b,n);i++)
        for (int j=max(y-a+1,0);j<min(y+a,m);j++)
            used[i][j]=true;
}

bool cmp(const pii& a,const pii& b){
    if (v[a.first][a.second]!=v[b.first][b.second])
        return v[a.first][a.second]<v[b.first][b.second];
    if (a.first!=b.first)
        return a.first<b.first;
    return a.second<b.second;
}

pair<int,int> q[1010*1010];

vector<int> ans1,ans2;
vector<int64> ans3;

int main()
{
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  scanf("%d %d %d %d",&n,&m,&b,&a);
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
        scanf("%d",&h[i][j]);
  genv();
  
  int ptr=0;
  for (int i=0;i<=n-b;i++)
    for (int j=0;j<=m-a;j++)
        q[ptr++]=mp(i,j);  
 sort(q,q+ptr,cmp);
  for (int i=0;i<ptr;i++)
    if (!used[q[i].first][q[i].second]){
        ans1.pb(q[i].first+1);
        ans2.pb(q[i].second+1);
        ans3.pb(v[q[i].first][q[i].second]);
        use(q[i].first,q[i].second);

    }
  int sz=ans1.size();
  printf("%d\n",sz);
  for (int i=0;i<sz;i++)
    printf("%d %d %lld\n",ans1[i],ans2[i],ans3[i]);
  
  return 0;
}
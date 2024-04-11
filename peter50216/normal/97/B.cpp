#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int in[10010][2];
pair<int,int> so[10010];
int out[200010][2];
int oc=0;
set<pair<int,int> > ss;
inline void solve(int l,int r){
    if(l==r)return;
    if(l==r-1){
	out[oc][0]=in[l][0];
	out[oc][1]=in[r][1];
	oc++;
	return;
    }
    int m=(l+r)/2;
    int i;
    for(i=l;i<=r;i++){
	out[oc][0]=in[m][0];
	out[oc][1]=in[i][1];
	oc++;
    }
    solve(l,m);
    solve(m+1,r);
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
	int a,b;
	scanf("%d%d",&a,&b);
	out[i][0]=a;
	out[i][1]=b;
	so[i].first=a;so[i].second=b;
    }
    sort(so,so+n);
    for(i=0;i<n;i++){
	in[i][0]=so[i].first;
	in[i][1]=so[i].second;
    }
    oc=n;
    solve(0,n-1);
    for(i=0;i<oc;i++)ss.insert(make_pair(out[i][0],out[i][1]));
    printf("%d\n",ss.size());
    for(set<pair<int,int> >::iterator it=ss.begin();it!=ss.end();it++)printf("%d %d\n",it->first,it->second);
}
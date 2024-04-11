#include<bits/stdc++.h>
using namespace std;
int t,n,k,res,f[220],a[110][2];
vector<int> b;
int main(){
	//freopen("C.in","r",stdin);
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k);
		res=0;
		for (int i=1;i<=2*n;i++) f[i]=0;
		for (int i=0;i<k;i++){
			scanf("%d%d",&a[i][0],&a[i][1]);
			if (a[i][0]<a[i][1]) swap(a[i][0],a[i][1]);
			f[a[i][0]]=f[a[i][1]]=1;
		}
		for (int i=1;i<=2*n;i++)
		if (!f[i]) b.push_back(i);
		for (int i=k;i<n;i++){
			a[i][1]=b[i-k];
			a[i][0]=b[i+n-2*k];
		}
		for (int i=0;i<n;i++){
			//printf("%d %d\n",a[i][0],a[i][1]);
			for (int j=i+1;j<n;j++)
			if ((a[i][0]-a[j][0])*(a[i][1]-a[j][1])>0&&(a[j][0]-a[i][1])*(a[j][1]-a[i][0])<0){
				//printf("%d %d %d %d\n",a[i][0],a[i][1],a[j][0],a[j][1]);
				res++;
			}
		}
		printf("%d\n",res);
		b.clear();
	}
}
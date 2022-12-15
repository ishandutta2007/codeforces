#include <bits/stdc++.h>
using namespace std;
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
int n,k,m,t;
int a[1010],b[1010];
int main(){
	cin>>n>>k>>m>>t;
	ref(i,1,n)a[i]=0;a[k]=1;
	int p=k;
	ref(i,1,t){
		int id,s;
		cin>>id>>s;
		if(id==0){
			if(p<=s)n=s;else{
				ref(i,1,n-s)a[i]=a[s+i];
				a[p]=0;p-=s;
				n-=s;
			}
		}
		if(id==1){
			def(i,n,s)a[i+1]=a[i];
			a[s]=0;n++;
			if(s<=p)p++;
		}
		cout<<n<<" "<<p<<endl;
	}
}
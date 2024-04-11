#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=100+5;
int n;
int s[maxn],b[maxn];
int main(){
	#ifdef LOCAL
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	#endif
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			int l=0,r=i;
			while(l<r){
				int mid=l+(r-l)/2;
				cout<<"1 "<<s[mid]<<" "<<i<<endl;
				int res;
				cin>>res;
				if(res) l=mid+1;
				else r=mid;
			}
			for(int j=i;j>r;j--) s[j]=s[j-1];
			s[r]=i;
		}
		int cur=n-1,cnt=0;
		memset(b,-1,sizeof(b));
		for(int i=n-1;i>=0;i--){
			if(i==cur) cur--;
			while(cur>=0){
				cout<<"2 "<<s[i]<<" "<<cur+1;
				for(int j=0;j<=cur;j++) cout<<" "<<s[j];
				cout<<endl;
				int res;
				cin>>res;
				if(!res) break;
				cur--;
			}
			if(b[s[i]]<0) b[s[i]]=cnt++;
			for(int j=cur+1;j<i;j++) b[s[j]]=b[s[i]];
		}
		cout<<"3"<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) cout<<(int)(b[i]>=b[j]);
			cout<<endl;
		}
		int tmp;
		cin>>tmp;
	}
	return 0;
}
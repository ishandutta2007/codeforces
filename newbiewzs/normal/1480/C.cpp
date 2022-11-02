
#include<bits/stdc++.h>
#define cl fflush(stdout)
#define int long long
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s; 
}
const int N=1e5+55;
int n;
int pd[N];
#define mid ((l+r)>>1)
void cdq(int l,int r){
	
	int you;
	if(pd[mid+1]){
		you=pd[mid+1];
	}
	else{
		cout<<"?"<<" "<<mid+1<<endl;
		cl;
		cin>>pd[mid+1];
		you=pd[mid+1];
	}
	int zuo;
	if(pd[mid-1]){
		zuo=pd[mid-1];
	}
	else{
		cout<<"?"<<" "<<mid-1<<endl;
		cl;
		cin>>pd[mid-1];
		zuo=pd[mid-1];
	}
	cout<<"?"<<" "<<mid<<endl;
	if(mid==2){
		new char;
	}
	cl;
	cin>>pd[mid];
	if(pd[mid]<you and pd[mid]<zuo){
		cout<<"!"<<" "<<mid;
		exit(0);
	}
	if(pd[mid+1]<pd[mid-1]){
		cdq(mid+1,r);
	}
	else{
		cdq(l,mid-1);
	}
}
signed main(){
	
	n=read();pd[0]=pd[n+1]=1e9;
	cdq(1,n);
	return 0;
}
/*
3000
1502
1500
1501
752
750
751
377
375
376
189
187
188
95
93
94
48
46
47
25
23
24
13
11
12
7
5
6
4
3
*/
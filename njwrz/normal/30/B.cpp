#include<bits/stdc++.h>
using namespace std;
int d1,m1;int y2;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
bool check(int d,int m,int y){
	if(m>12)return 0;
	if(y%4==0){
		if(m==2){
			if(d<=29)return 1;
		}else return (d<=mon[m]);
	}
	return (d<=mon[m]);
}
bool f(int d,int m,int y){
	int q=y+18;
	if(q!=y2){
		return (y2>q);
	}; 
	if(m!=m1){
		return (m1>m);
	}
	return (d1>=d);
}
int main(){
	int d,m,y;
	scanf("%d.%d.%d",&d1,&m1,&y2);
	scanf("%d.%d.%d",&d,&m,&y);
	if(check(d,m,y)){
		if(f(d,m,y)){
			cout<<"YES";return 0;
		}
	}
	if(check(d,y,m)){
		if(f(d,y,m)){
			cout<<"YES";return 0;
		}
	}
	if(check(m,d,y)){
		if(f(m,d,y)){
			cout<<"YES";return 0;
		}
	}
	if(check(m,y,d)){
		if(f(m,y,d)){
			cout<<"YES";return 0;
		}
	}
	if(check(y,m,d)){
		if(f(y,m,d)){
			cout<<"YES";return 0;
		}
	}
	if(check(y,d,m)){
		if(f(y,d,m)){
			cout<<"YES";return 0;
		}
	}
	cout<<"NO";
	return 0;
}
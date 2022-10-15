#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sec second
#define rep(a,b,c) for(int a=1;a<=b;a+=c)
#define repp(a,b,c,d) for(int a=b;a<=c;a+=d)
 
const double PI=acos(-1);
const double EPS=1e-12;
const int MOD=1e9+7;
const int INF=1<<30;
 
 
using namespace std;
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(abs(c-d)>1)cout<<"-1"<<endl;
	else if(a<max(c,d)||b<max(c,d))cout<<"-1"<<endl;
	else if(a==b&&a==c&&a==d)cout<<"-1"<<endl;
	else{
		if(c>d){
			rep(i,a-c,1)cout<<"4";
			rep(i,c,1)cout<<"47";
			rep(i,b-c,1)cout<<"7";
		}
		else if(c<d){
			rep(i,d-1,1){
				cout<<"74";
				if(i==1)rep(i,a-d,1)cout<<"4";
			}
			rep(i,b-d+1,1)cout<<"7";
			cout<<"4"<<endl;
		}
		else{
			if(a>b){
				rep(i,a-c-1,1)cout<<"4";
				rep(i,c,1)cout<<"47";
				rep(i,b-d,1)cout<<"7";
				cout<<"4";
			}
			else if(a<b){
				if(a>max(c,d)){
					rep(i,a-max(c,d)-1,1)cout<<"4";
					rep(i,c,1)cout<<"47";
					rep(i,b-d,1)cout<<"7";
					cout<<"4";
				}
				else{
					rep(i,d,1){
						cout<<"74";
						if(a<=max(c,d)&&i==d)rep(i,b-d,1)cout<<"7";
					}
				}
			}
			else if(a==b){
				rep(i,a-c-1,1)cout<<"4";
				rep(i,c,1)cout<<"47";
				rep(i,b-c-1,1)cout<<"7";
				rep(i,d-c+1,1)cout<<"74";
			}		
		}
	}
}
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
void out(){
	cout<<"NO";exit(0);
} 
bool check(char c){
	RE (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c=='_')||(c>='0'&&c<='9');
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int t1=s.find("@");
	if(t1==-1||!t1||t1>=16)out();
	rep(i,0,t1){
		if(!check(s[i]))out();
	}
	int t2=s.find("/");
	if(t2==-1)t2=s.size();
	if(t2-t1<2||t2-t1>33)out();
	int len=0;
	rep(i,t1+1,t2){
		if(s[i]=='.'){
			if(!len||len>16)out();
			len=0;
		}else{
			if(!check(s[i]))out();
			len++;
		}
	}
	if(!len||len>16)out();
	if(t2==s.size()){
		cout<<"YES";RE 0;
	}
	len=0;
	t2++;
	rep(i,t2,s.size()){
		if(s[i]=='/'){
			if(!len||len>16)out();
			len=0;
		}else{
			if(!check(s[i]))out();
			len++;
		}
	}
	if(!len||len>16)out();
	cout<<"YES";    
	RE 0;
}
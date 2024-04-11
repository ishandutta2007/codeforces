#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int t[1<<22][2];
int nt;
int x[1<<22];
string s;

void add(){
	int k=0;
	fore(i,0,s.size()){
		int d=(s[i]-'0')%2;
		if(t[k][d]<0){
			t[k][d]=nt++;
		}
		k=t[k][d];
		x[k]++;
	}
}

void erase(){
	int k=0;
	fore(i,0,s.size()){
		int d=(s[i]-'0')%2;
		assert(t[k][d]>0);
		k=t[k][d];
		x[k]--;
	}
}

int query(){
	int k=0;
	fore(i,0,s.size()){
		int d=(s[i]-'0')%2;
		if(t[k][d]<0)return 0;
		k=t[k][d];
	}
	return x[k];
}

int main(){
	nt=1;
	memset(t,-1,sizeof(t));
	int q;
	scanf("%d",&q);
	while(q--){
		char c;
		cin>>c>>s;
		reverse(s.begin(),s.end());
		fore(_,0,18-s.size())s.pb('0');
		if(c=='+')add();
		else if(c=='-')erase();
		else printf("%d\n",query());
	}
	return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int next[1<<23][2];
int s[1<<23];
int sz;

void add(int x){
	int k=0;
	s[k]++;
	for(int i=31;i>=0;--i){
		int d=(x>>i)&1;
		if(next[k][d]<0)next[k][d]=sz++;
		k=next[k][d];
		s[k]++;
	}
}

void erase(int x){
	int k=0;
	s[k]--;
	for(int i=31;i>=0;--i){
		int d=(x>>i)&1;
		assert(next[k][d]>=0);
		k=next[k][d];
		assert(s[k]>0);
		s[k]--;
	}
}

int query(int x){
	int r=0,k=0;
	assert(s[k]>0);
	for(int i=31;i>=0;--i){
		int d=(x>>i)&1;
		if(next[k][1-d]>=0&&s[next[k][1-d]]>0){
			k=next[k][1-d];
			r+=(1<<i);
		}
		else k=next[k][d];
		assert(s[k]>0);
	}
	return r;
}

char c[4];

int main(){
	memset(next,-1,sizeof(next));
	sz=1;
	add(0);
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%s %d",c,&x);
		if(c[0]=='+')add(x);
		else if(c[0]=='-')erase(x);
		else printf("%d\n",query(x));
	}
	return 0;
}
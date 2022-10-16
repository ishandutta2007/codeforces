#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



struct tri{
	int a,b,c,i;
};

vector <tri> s;

void cr(int a,int b,int c,int i){
	tri n;n.a = a;n.b = b;n.c = c;n.i = i;
	s.push_back(n);
}

bool cmp(tri a,tri b){
	if(a.a == b.a){
		if(a.b==b.b) return a.c<b.c;
		return a.b<b.b;
	}
	return a.a < b.a;
}

int n,x,y,z;

int mx = -1;
int k = 1;
int ind1,ind2 = -1;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d %d %d",&x,&y,&z);
		     if(x >= y && y >= z) cr(x,y,z,i+1);
		else if(x >= z && z >= y) cr(x,z,y,i+1);
		else if(y >= x && x >= z) cr(y,x,z,i+1);
		else if(y >= z && z >= x) cr(y,z,x,i+1);
		else if(z >= x && x >= y) cr(z,x,y,i+1);
		else cr(z,y,x,i+1);
		if(min(x,min(y,z)) > mx){
			ind1 = i+1;
			mx = min(x,min(y,z));
		}
	}
	
	sort(s.rbegin(),s.rend(),cmp);
	for(int i = 0;i<n;){
		int ci = i;
		while(s[i].a == s[ci].a && s[i].b == s[ci].b){
			i++;
			if(i == n) break;
		}
		if(i-ci <= 1) continue;
		if(min(s[ci].a,min(s[ci].b,s[ci].c+s[ci+1].c)) > mx){
			mx = min(s[ci].a,min(s[ci].b,s[ci].c+s[ci+1].c));
			k = 2;
			ind1 = s[ci+1].i;
			ind2 = s[ci].i;
		}
	}
	if(k == 1){
		printf("1\n");
		printf("%d\n",ind1);
	}
	else{
		printf("2\n");
		printf("%d %d\n",min(ind1,ind2),max(ind1,ind2));
	}
}
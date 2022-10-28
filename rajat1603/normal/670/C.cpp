#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
map < int , int > mp;
int m;
int a , b;
int x = 1 , y = 0 , z = 0;
int aa[N];
int bb[N];
int main(){
	scanf("%d" , &n);
	mp.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , &m);
		++mp[m];
	}
	scanf("%d" , &m);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , aa + i);
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d" , &bb[i]);
		a = aa[i];
		b = bb[i];
		int c = mp[a];
		int d = mp[b];
		if(c > y){
			y = c;
			z = d;
			x = i;
		}
		else if(c == y && d > z){
			z = d;
			x = i;
		}
	}
	cout << x;
}
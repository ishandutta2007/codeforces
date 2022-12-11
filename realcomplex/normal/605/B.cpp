#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

struct Edge{
	int weight;
	int has;
	int index;
	bool operator< (Edge T){
		if(weight == T.weight){
			return has > T.has;
		}
		else{
			return weight < T.weight;
		}
	}
};

int main(){
	fastIO;
	int n, m ;
	cin >> n >> m;
	Edge Y[m];
	for(int i = 0 ;i  < m ; i ++ ){
		cin >> Y[i].weight >> Y[i].has;
		Y[i].index = i;
	}
	sort(Y, Y + m);
	int p = 1;
	int f[m];
	int t[m];
	int sx, sy;
	int us = 0;
	int tl = 3;
	int tr = 1;
	for(int i = 0 ; i < m ; i ++ ){
		if(Y[i].has){
			f[Y[i].index] = p;
			p ++ ;
			t[Y[i].index] = p;
		}
		else{
			if(tl > p){
				cout << -1;
				return 0;
			}
			f[Y[i].index] = tl;
			t[Y[i].index] = tr;
			tr -- ;
			if(tr == 0){
				tl ++ ;
				tr = tl - 2;
			}
		}
	}
	for(int i = 0; i < m ; i ++ ){
		cout << f[i] << " " << t[i] << "\n";
	}
	return 0;
}
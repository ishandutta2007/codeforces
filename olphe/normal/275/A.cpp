#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<vector<int>>v(3,vector<int>(3));
	for(auto &i:v)for(auto &j:i)cin>>j;
	vector<vector<int>>w(3,vector<int>(3,1));
	int diry[]={1,0,0,0,-1};
	int dirx[]={0,-1,0,1,0};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(v[i][j]&1){
				for(int k=0;k<5;k++){
					int ny=i+diry[k];
					int nx=j+dirx[k];
					if(ny<0||nx<0||ny>=3||nx>=3)continue;
					w[ny][nx]^=1;
				}
			}
		}
	}
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)cout<<w[i][j];
		cout<<endl;
	}
}
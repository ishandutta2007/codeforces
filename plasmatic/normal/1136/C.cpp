//============================================================================
// Name        : 546C.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Scan and Debug
void scan(){}
template<typename F, typename... R> void scan(F &f,R&... r){cin>>f;scan(r...);}
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R> void debug_(F f, R... r){while(dnms_[di_] != ',')cout<<dnms_[di_++];di_++;cout<<": "<<f<<",";debug_(r...);}
#define debug(...) dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__)

const int MAX = 501;
int n, m,
	mat1[MAX][MAX], mat2[MAX][MAX];

inline void scanGrid(int mat[MAX][MAX]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scan(mat[i][j]);
}

inline bool equals(unordered_map<int, int> &first, unordered_map<int, int> &second){
	for(pair<int, int> entry : first)
		if(entry.second != second[entry.first])
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	scan(n, m);
	scanGrid(mat1);
	scanGrid(mat2);

	int diagCnt = n + m - 1;
	for (int i = 0; i < diagCnt; ++i) {
		int x = i, y = 0;
		if(i >= n){
			x = n - 1;
			y = i - n + 1;
		}

		unordered_map<int, int> map1, map2;
		for (; x >= 0 && y < m; x--, y++){
			//debug(i, x, y, mat1[x][y]);
			map1[mat1[x][y]]++;
			map2[mat2[x][y]]++;
		}

		if(!equals(map1, map2)){
			printf("NO\n");
			return 0;
		}
	}

	printf("YES\n");

	return 0;
}
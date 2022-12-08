										/* in the name of Allah */
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <list>
#include <map>
#include <set>

using namespace std;

#define uint unsigned int
#define int64 long long
#define P pair<int, int>
#define Pss pair<string, string>
#define PLL pair<int64, int64>
#define Inf 1000000
#define Mod 1000000007LL

int K, n;
int a[210];
int oth[210], in[210];

int main(){
	cin >> n >> K;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int mx = a[0];
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			int sum = 0, cnt = 0, fir = 0;
			for(int k = 0; k < n; k++){
				if(i <= k && k <= j){
					sum += a[k];
					in[fir++] = a[k];
				}
				else oth[cnt++] = a[k];
			}
			sort(oth, oth + cnt);
			reverse(oth, oth + cnt);
			sort(in, in + fir);
			int pnt = 0;
			for(int k = 0; k < cnt && k < K; k++){
				if(pnt < fir){
					if(oth[k] > 0 || oth[k] > in[pnt]){
						sum += oth[k] - in[pnt];
						if(in[pnt] > 0)
							sum += in[pnt];
						else pnt++;
					}
				}
				else if(oth[k] > 0)
					sum += oth[k];
			}
			mx = max(mx, sum);
		}
	}
	cout << mx << endl;
	return 0;
}
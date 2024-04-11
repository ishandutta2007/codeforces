#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define inf 1000000000
using namespace std;
typedef long long ll;

ll Sum[1000000];
ll _max = 0;
ll A[1000000];
multiset<int> elem;
int main(){
	int n, w;
	cin >> n >> w;
	fill(Sum, Sum + w, 0);
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		for(int j=0;j<m;j++){
			cin >> A[j];
		}
		if(m * 2 > w){
			elem.clear();
			for(int k=0;k<w;k++){
				if(k < m){
					elem.insert(A[k]);
				}
				if(k >= m || k < w - m){
					Sum[k] += max(0, *(--elem.end()));
				}else{
					Sum[k] += *(--elem.end());
				}
				if(k >= w - m){
					auto itr(elem.find(A[k - (w - m)]));
					elem.erase(itr);
				}
			}
		}else{
			ll O_Max = max(0LL, *max_element(A, A+m));
			_max += O_Max;
			ll Max = 0;
			for(int k=0;k<m;k++){
				Max = max(Max, A[k]);
				Sum[k] += Max - O_Max;
			}
			Max = 0;
			for(int k=w-1;k>=w-m;k--){
				Max = max(Max, A[k-(w-m)]);
				Sum[k] += Max - O_Max;
			}
		}
	}
	for(int i=0;i<w;i++){
		cout << _max + Sum[i] << ' ';
	}
	cout << endl;
}
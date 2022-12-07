#include <bits/stdc++.h>

using namespace std;

const int K = 15;
const int N = 1e5 + 10;

int n, k;
int a[N][K];

struct Data{
	int valMax[K], valMin[K];
	int elements;

	Data (){
		memset(valMax, -1, sizeof valMax);
		memset(valMin, 60, sizeof valMin);
		elements = 0;
	}

	bool operator <(const Data &other)const {
		for(int i = 1; i <= k; ++i){
			if(valMax[i] != other.valMax[i]){
				return valMax[i] < other.valMax[i];
			}
		}
	}
};

Data Combine(Data u, Data v){
	for(int i = 1; i <= k; ++i){
		u.valMax[i] = max(u.valMax[i], v.valMax[i]);
		u.valMin[i] = min(u.valMin[i], v.valMin[i]);
	}
	u.elements += v.elements;
	return u;
}

bool Can(Data u, Data v){
	int ans = 0;
	for(int i = 1; i <= k; ++i){
		if(u.valMax[i] > v.valMin[i]) ans |= 1;
		if(u.valMin[i] < v.valMax[i]) ans |= 2;
	}
	return (ans == 3);
}

set < Data > heap;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= k; ++j){
			scanf("%d", a[i] + j);
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i){
		Data mic;
		for(int j = 1; j <= k; ++j){
			mic.valMax[j] = mic.valMin[j] = a[i][j];
			mic.elements = 1;
		}


		if(heap.empty()){
			heap.insert(mic);
			printf("1\n");   
			continue;                                       
		}

		while(!heap.empty()){
			auto it = heap.lower_bound(mic);
			if(it == heap.begin()) break;

			--it;
			if(Can(*it, mic)){
				mic = Combine(mic, *it);
				heap.erase(it);
			}
			else break;
		}



		while(!heap.empty()){
			auto it = heap.lower_bound(mic);
			if(it == heap.end()) break;

			if(Can(*it, mic)){
				mic = Combine(mic, *it);
				heap.erase(it);
			}
			else break;
		}


		heap.insert(mic);
		printf("%d\n", heap.rbegin() -> elements);
	}

	return 0;

}
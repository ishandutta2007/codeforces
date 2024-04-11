//============================================================================
// Name        : 514C.cpp
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

const int MAX = 21;
int n, maxpower, biggestForMax,
	power[MAX];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	scan(n);

	for(int i = 0; (1 << i) <= n; i++)
		maxpower = i;

	for(int i = 1; i <= n; i++){
		int curpower = 0;
		for(int j = i; (j & 1) == 0; j >>= 1)
			curpower++;

		power[curpower]++;
		if(curpower >= maxpower - 1)
			biggestForMax = max(biggestForMax, i);
	}

	bool printMax = false;
	if(biggestForMax > (1 << maxpower))
		printMax = true;

	for (int i = 0; i <= maxpower; ++i) {
		if(i == maxpower && printMax)
			printf("%d ", biggestForMax);
		else{
			int val = 1 << i;
			for(int j = 0; j < power[i]; j++)
				printf("%d ", val);
		}
	}
	printf("\n");

	return 0;
}
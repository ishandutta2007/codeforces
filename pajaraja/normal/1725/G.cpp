#include<bits/stdc++.h>

using namespace std;

long long N;

int main() {
    cin >> N;

    long long lo = 0;
    long long ro = 1e18;


    while(lo < ro - 1) {
    	long long mid = lo + ro >> 1;

    	if ((mid - 1)/2 + (mid - 4)/4 < N)  lo = mid; else ro = mid;
    }
   
   cout << lo + 1 << endl;
}
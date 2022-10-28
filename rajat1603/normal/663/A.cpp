#include "bits/stdc++.h"
using namespace std;
string str;
int n;
int add = 1;
int sub = 0;
vector < int > v;
int main(){
	v.push_back(1);
	while(1){
		cin >> str;
		if(str == "="){
			break;
		}
		if(str == "?"){
			continue;
		}
		else if(str == "+"){
			++add;
			v.push_back(1);
		}
		else{
			++sub;
			v.push_back(-1);
		}
	}
	cin >> n;
	int mx = n * add - sub;
	int mn = add - n * sub;
	if(n > mx || n < mn){
		printf("Impossible\n");
		return 0;
	}
	int cur = add - sub;
	priority_queue < pair < int , int > > pq1 , pq2;
	map < int , int > ans1;
	map < int , int > ans2;
	for(int i = 1 ; i <= add ; ++i){
		pq1.push(make_pair(i , n - 1));
		++ans1[i];
	}
	for(int i = 1 ; i <= sub ; ++i){
		pq2.push(make_pair(i , n - 1));
		++ans2[i];
	}
	while(cur != n){
		if(cur < n){
			if(pq1.empty()){
				printf("Impossible\n");
				return 0;
			}
			auto it = pq1.top();
			pq1.pop();
			if(it.second > 0){
				--it.second;
				++ans1[it.first];
				pq1.push(it);
				++cur;
			}
			else{
				continue;
			}
		}
		else{
			if(pq1.empty()){
				printf("Impossible\n");
				return 0;
			}
			auto it = pq2.top();
			pq2.pop();
			if(it.second > 0){
				--it.second;
				++ans2[it.first];
				pq2.push(it);
				--cur;
			}
			else{
				continue;
			}
		}
	}
	printf("Possible\n");
	int szp = 0;
	int szn = 0;
	for(int x : v){
		if(x == 1){
			++szp;
			if(szp != 1){
				printf(" + ");
			}
			printf("%d" , ans1[szp]);
		}
		else{
			++szn;
			printf(" - ");
			printf("%d" , ans2[szn]);
		}
	}
	printf(" = %d" , n);
}
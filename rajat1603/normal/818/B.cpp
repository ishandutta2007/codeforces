#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , m;
int l[N];
int arr[N];
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= m ; ++i){
		cin >> l[i];
	}
	memset(arr , -1 , sizeof(arr));
	for(int i = 1 ; i < m ; ++i){
		arr[l[i]] = l[i + 1] - l[i];
		if(arr[l[i]] <= 0){
			arr[l[i]] += n;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		--l[i];
	}
	for(int i = 1 ; i < m ; ++i){
		if(l[i + 1] != ((l[i] + arr[l[i] + 1]) % n)){
			printf("-1\n");
			return 0;
		}
	}
	set < int > s;
	s.clear();
	for(int i = 1 ; i <= n ; ++i){
		s.insert(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		s.erase(arr[i]);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i] == -1){
			arr[i] = *s.begin();
			s.erase(s.begin());
		}
	}
	if(!s.empty()){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		printf("%d%c" , arr[i] , " \n"[i == n]);
	}
}
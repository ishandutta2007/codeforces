#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
int mid , two;
int main(){
	scanf("%d %d" , &n , &k);
	mid = n;
	two = n + n;
	for(int i = 1 ; i <= k ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= k ; ++i){
		while(arr[i] >= 4){
			if(mid){
				--mid;
				arr[i] -= 4;
			}
			else{
				if(two >= 2){
					two -= 2;
					arr[i] -= 4;
				}
				else{
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	for(int i = 1 ; i <= k ; ++i){
		if(arr[i] == 3){
			if(mid){
				--mid;
				arr[i] = 0;
			}
			else if(two >= 2){
				two -= 2;
				arr[i] = 0;
			}
			else{
				printf("NO\n");
				return 0;
			}
		}
	}
	int ones , twos;
	ones = 0;
	twos = 0;
	for(int i = 1 ; i <= k ; ++i){
		if(arr[i] == 2){
			++twos;
		}
		else if(arr[i] == 1){
			++ones;
		}
	}
	while(min(ones , twos)){
		if(mid){
			--mid;
			--ones;
			--twos;
		}
		else{
			break;
		}
	}
	while(twos >= 3 && mid >= 2){
		twos -= 3;
		mid -= 2;
	}
	while(ones >= 2){
	    if(mid){
	        ones -= 2;
	        --mid;
	    }
	    else{
	        break;
	    }
	}
	two += mid;
	twos += ones;
	while(twos){
		if(two){
			--two;
			--twos;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
}
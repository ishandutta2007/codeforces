#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n,q;
int a[1000005];
int cnt = 0;
int skip = -1;
int b[1000005];
vector <int> output1;
vector <string> output2;

int main(){
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);
	}
	scanf("%d",&q);
	for(int i = 0;i<q;i++){
		scanf("%d",b+i);
	}
	int j = 0;
	for(int i = 0;i<n;){
		int ci = i;
		int sm = 0;
		while(sm < b[j]){
			sm += a[i];
			i++;
			if(i == n) break;
		}
		
		if(sm != b[j]){
			printf("NO\n");
			return 0;
		}
		j++;
		if(j == q && i < n){
			printf("NO\n");
			return 0;
		}
		if(ci == i-1) continue;
		int mx = -1;
		int ind;
		bool as = false;
		for(int k = ci+1;k < i-1;k++){
			if(a[k] > mx ||(a[k] == mx && as == false)){
				mx = a[k];
				ind = k;
				as = (a[k-1] < a[k] || a[k+1] < a[k]);
			}

		}
		if(a[ci] > mx || (a[ci] == mx && as == false)){
			mx = a[ci];ind=ci;as=(a[ci+1]<a[ci]);
		}
		if(a[i-1] > mx ||(a[i-1]==mx&&as==false)){
			mx=a[i-1];ind=i-1;as=(a[i-2]<a[i-1]);
		}
		if(!as){
			printf("NO\n");
			return 0;
		}
		int addskip = 0;
		if(ind == ci || a[ind] > a[ind+1]){
			for(int k = ind+1;k<i;k++){
				output1.push_back(ind-skip);
				output2.push_back(" R\n");
				addskip++;
			}
			for(int k = ci;k<ind;k++){
				output1.push_back(ind-skip);
				output2.push_back(" L\n");
				skip++;
			}
			skip += addskip;
		}
		else{
			for(int k = ci;k<ind;k++){
				output1.push_back(ind-skip);
				output2.push_back(" L\n");
				skip++;
			}
			for(int k = ind+1;k<i;k++){
				output1.push_back(ind-skip);
				output2.push_back(" R\n");
				addskip++;
			}
			skip += addskip;
		}
	}
	if(j != q) {printf("NO\n");return 0;}
	printf("YES\n");
	for(int i = 0;i<output1.size();i++){
		cout << output1[i] << output2[i];
	}
}
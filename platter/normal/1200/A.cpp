#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main(void) {
	int n;
	scanf("%d\n",&n);
	char str[100001];
	scanf("%s",str);
	for(int i=0;i<n;i++) {
		if (str[i]=='L') {
			for(int j=0;j<10;j++) {
				if (arr[j]==0) {
					arr[j]=1;
					break;
				}
			}
		}
		else if (str[i]=='R') {
			for(int j=9;j>=0;j--) {
				if (arr[j]==0) {
					arr[j]=1;
					break;
				}
			}
		}
		else {
			arr[str[i]-'0']=0;
		}
	}
	for(int i=0;i<10;i++) {
		printf("%d",arr[i]);
	}
}
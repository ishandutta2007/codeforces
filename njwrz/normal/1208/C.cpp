#include <bits/stdc++.h>
using namespace std;
inline void write(int x){
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j&1){
				write((j-1)*n+(i-1)*2);
			}else{
				write((j-2)*n+(i-1)*2+1);
			}
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
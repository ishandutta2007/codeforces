#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;

int a[N],b[N],n,k;

int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i = 0;i<k;i++){
        scanf("%d",b+i);
    }
    sort(b,b+k);
    reverse(b,b+k);
    int j = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == 0){
            a[i] = b[j];j++;
        }
    }
    for(int i = 0;i<n-1;i++){
        if(a[i+1] < a[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
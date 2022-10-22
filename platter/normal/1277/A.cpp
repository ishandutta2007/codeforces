#include <cstdio>
#include <algorithm>
using namespace std;

long long arr[100];
int size=0;

void makearray() {
    for(int i=1;i<10;i++) {
        long long plus=i;
        long long val=i;
        while (val<10000000000) {
            arr[size]=val;
            size+=1;
            plus*=10;
            val+=plus;
        }
    }
}

int main(void) {
    makearray();
    sort(arr,arr+size);
    int c;
    scanf("%d\n",&c);
    for(int t=0;t<c;t++) {
        int n;
        scanf("%d\n",&n);
        for(int i=0;i<size;i++) {
            if (arr[i]>n) {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
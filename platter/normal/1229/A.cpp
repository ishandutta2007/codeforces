#include <bits/stdc++.h>
using namespace std;

long long arr[7000];
int b[7000];
bool two[7000];

int main(void) {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&arr[i]);
    }
    for(int i=0;i<n;i++) {
        scanf("%d",&b[i]);
    }
    vector<long long> v;
    long long sum=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (j!=i) {
                if (arr[j]==arr[i]) {
                    if (j<i) {
                        sum+=b[i];
                        two[i]=true;
                        break;
                    }
                    sum+=b[i];
                    two[i]=true;
                    v.push_back(arr[i]);
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        if (!two[i]) {
            for(int j=0;j<v.size();j++) {
                if ((arr[i]&v[j])==arr[i]) {
                    v.push_back(arr[i]);
                    sum+=b[i];
                    break;
                }
            }
        }
    }
    printf("%lld",sum);
}
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector  <int> a;
int cur;

int main(){
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&cur);
        a.push_back(cur);
    }
    sort(a.begin(),a.end());
    int mex = 1;
    for(int k = 0;k<n;k++){
        int i = a[k];
        if(i == mex){
            mex++;
        }
        if(i > mex){
            mex++;

        }
    }
    printf("%d\n",mex);
}
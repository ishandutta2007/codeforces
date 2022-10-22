#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> psum[200001];

int main(void) {
    char str[200001];
    scanf("%s\n",str);
    for(int i=0;i<26;i++) {
        psum[0].push_back(0);
    }
    int n=strlen(str);
    for(int i=0;i<n;i++) {
        psum[i+1]=psum[i];
        psum[i+1][str[i]-'a']++;
    }
    int q;
    scanf("%d\n",&q);
    for(int i=0;i<q;i++) {
        int l,r;
        scanf("%d %d\n",&l,&r);
        if (l==r) {
        	printf("Yes\n");
        	continue;
        }
        vector<int> cnt;
        for(int j=0;j<26;j++) {
            cnt.push_back(psum[r][j]-psum[l-1][j]);
        }
        int letters=0;
        for(int j=0;j<26;j++) {
            if (cnt[j]!=0) {
                letters++;
            }
        }
        if (letters<=2&&str[l-1]==str[r-1]) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }
}
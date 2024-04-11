#include <bits/stdc++.h>

using namespace std;

vector<int> root1;
vector<int> child;

int main()
{
    int t;
    scanf("%d", &t);
    for (int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int c1=1, c2=0, root;
        scanf("%d", &root);
        root1.push_back(1);
        for (int j=1;j<n;j++){
            int tmp;
            scanf("%d", &tmp);
            if (tmp==root) {
                c1 += 1;
                root1.push_back(j+1);
            }
            else {
                c2 += 1;
                child.push_back(j+1);
            }
        }
        if (c2 == 0) printf("NO\n");
        else{
            printf("YES\n");
            for (int j=0;j<c2;j++) printf("1 %d\n", child[j]);
            for (int j=1;j<c1;j++) printf("%d %d\n", root1[j], child[0]);
        }
        root1.clear();
        child.clear();
    }
    return 0;
}
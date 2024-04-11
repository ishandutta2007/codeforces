#include <bits/stdc++.h>

using namespace std;
vector<int> number;
vector<int> price;
int ans[100003]={0};
int c=0;

int main()
{
    int n;
    scanf("%d", &n);
    bool test=0;
    char tmp;
    for (int i=0;i<2*n;i++){
        //printf("%d\n", c);
        int tmpint=0;
        scanf(" %c", &tmp);
        if (tmp ==43) {
            //printf("yes\n");
            price.push_back(0);
            number.push_back(c);
            c = c+1;
        }
        else if (price.size()==0) {
            test=1;
            scanf("%d", &tmpint);
        }
        else{
            scanf("%d", &tmpint);
            if (tmpint<price.back()) {
                test=1;
            }
            else{
                ans[number.back()]=tmpint;
                number.pop_back();
                price.pop_back();
                if (price.size()!=0) price[price.size()-1]=max(tmpint, price.back());
            }
        }
        /*printf("%d\n", c);
        for (int j=0;j<price.size();j++) printf("%d ", price[j]);
        printf("\n");
        for (int j=0;j<number.size();j++) printf("%d ", number[j]);
        printf("\n");*/
    }
    if (test) printf("NO");
    else{
        printf("YES\n");
        for (int i=0;i<n;i++) printf("%d ", ans[i]);
    }
    return 0;
}
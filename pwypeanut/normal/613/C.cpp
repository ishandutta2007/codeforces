#include <bits/stdc++.h>
using namespace std;

int N, arr[26];

int gcd(int a, int b) {
    if (min(a, b) == 0) return max(a, b);
    else return gcd(max(a, b) % min(a, b), min(a, b));
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int sum = 0;
    for (int i = 0; i < N; i++) sum += (arr[i] > 0);
    if (sum == 0) {
        printf("0\n\n");
        return 0;
    } else if (sum == 1) {
        int tlen = 0;
        for (int i = 0; i < N; i++) tlen += arr[i];
        printf("%d\n", tlen);
        for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]; j++) printf("%c", 'a' + i);
        printf("\n");
        return 0;
    } else {
        int sum2 = 0;
        for (int i = 0; i < N; i++) sum2 += (arr[i] % 2 == 1);
        if (sum2 == 0) {
            // even length
            int g = arr[0];
            for (int i = 1; i < N; i++) g = gcd(g, arr[i]);
            int sum3 = 0;
            for (int i = 0; i < N; i++) sum3 += ((arr[i] / g) % 2 == 1);
            if (sum3 > 1) {
            
g/=2;
sum3=0;
for(int i=0;i<N;i++)sum3+=((arr[i]/g)%2==1);
}
            if (true) {
                // resultant can be made into palindrome
                if (sum3 == 0) {
                
printf("%d\n",2*g);
                    for (int k = 0; k < g; k++) {
                    
                        for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                        for (int i = N-1; i >= 0; i--) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                    }
                } else {
                
printf("%d\n",g);
                    for (int k = 0; k < g; k++) {
                        for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                        for (int i = 0; i < N; i++) if ((arr[i]/g) % 2 == 1) printf("%c", 'a' + i);
                        for (int i = N-1; i >= 0; i--) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                    }
                }
                printf("\n");
            }
        } else if (sum2 == 1) {
            // odd length - string, b, string
            int g = arr[0];
            for (int i = 1; i < N; i++) g = gcd(g, arr[i]);
            int sum3 = 0;
            for (int i = 0; i < N; i++) sum3 += ((arr[i] / g) % 2 == 1);
            if (sum3 > 1) g /= 2;
            if (true) {
                // resultant can be made into palindrome
                printf("%d\n", g);
                if (sum3 == 0) {
                    for (int k = 0; k < g; k++) {
                        for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                        for (int i = N-1; i >= 0; i--) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                    }
                } else {
                    for (int k = 0; k < g; k++) {
                        for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                        for (int i = 0; i < N; i++) if ((arr[i]/g) % 2 == 1) printf("%c", 'a' + i);
                        for (int i = N-1; i >= 0; i--) for (int j = 0; j < arr[i]/g/2; j++) printf("%c", 'a' + i);
                    }
                }
                printf("\n");
            }
        } else {
            printf("0\n");
            for (int i = 0; i < N; i++) for (int j = 0; j < arr[i]; j++) printf("%c", 'a' + i);
            printf("\n");
        }
    }
}
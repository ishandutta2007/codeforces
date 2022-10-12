#include<cstdio>
#include<vector>

long long t, a, b;

int main() {
    scanf("%I64d %I64d %I64d", &t, &a, &b);
    if (t == a) {
        if (a == b) {
            if (t == 1) printf("inf\n");
            else printf("2\n");
        } else printf("0\n");
    } else if (t < a) {
        if (a == b) printf("1\n");
        else if (a < b) {
            std::vector <long long> base;
            long long tmp = b;
            while (tmp) {
                base.push_back(tmp % a);
                tmp /= a;
            }

            tmp = 0;
            while (base.size() > 1) {
                tmp += base.back();
                tmp *= t;
                base.pop_back();
            }

            if (tmp + base[0] == a) printf("1\n");
            else if (t == 1) {
                if (b % a == 0) printf("1\n");
                else printf("0\n");
            }
            else printf("0\n");

        } else printf("0\n");
    } else {
        if (a == b) printf("1\n");
        else printf("0\n");
    }
    return 0;
}
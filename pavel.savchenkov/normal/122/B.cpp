    #include <cstdio>
    #include <cstring>

    using namespace std;

    int main() {
            char s[100];
            scanf("%s",&s);
            int k4=0,k7=0;
            for (int i=0;i<strlen(s);i++)
                    if (s[i]=='4') k4++; else if (s[i]=='7') k7++;
            if (k4==0&k7==0) printf("-1"); else
                    if (k4>=k7|k7==0) printf("4"); else printf("7");
            return 0;
    }
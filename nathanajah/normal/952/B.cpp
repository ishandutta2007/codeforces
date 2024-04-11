#include <bits/stdc++.h>
using namespace std;



string removenonalphabetic(string s) {
    string result = "";
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            result.append(1, c);
        }
    }
    return result;
}

int main() {
    string grumps[6] = {"don't even", "are you serious?", "go die in a hole", "worse", "terrible", "no way"};
    string norms[5] = {"don't think so", "don't touch me!", "great!", "not bad", "cool"};
    bool grumpy = false;
    bool decided = false;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
        fflush(stdout);
        char tmp[10000];
        fgets(tmp, 1000, stdin);
        int ln = strlen(tmp);
        tmp[ln - 1] = '\0';
        string tmps = tmp;
        for (int j = 0; j < 6; j++) {
            string grump = grumps[j];
            if (removenonalphabetic(tmps) == removenonalphabetic(grump)) {
                grumpy = true;
                decided = true;
                break;
            }
        }
        for (int j = 0; j < 5; j++) {
            string normm = norms[j];
            if (removenonalphabetic(normm) == removenonalphabetic(tmps)) {
                grumpy = false;
                decided = true;
                break;
            }

        }
        if (decided) {
            break;
        }
    }
    printf(grumpy ? "grumpy\n" : "normal\n");
}
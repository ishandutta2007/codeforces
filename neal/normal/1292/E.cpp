#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
string P;

bool finished() {
    return count(P.begin(), P.end(), '?') == 0;
}

void answer() {
    for (int i = 0; i < N; i++)
        assert(P[i] != '?');

    cout << "! " << P << endl;
    int outcome;
    cin >> outcome;

    if (outcome == 0)
        exit(0);
}

int query(string str) {
    cout << "? " << str << endl;
    int k;
    cin >> k;

    if (k < 0)
        exit(0);

    for (int rep = 0; rep < k; rep++) {
        int a;
        cin >> a;
        a--;

        for (int i = 0; i < (int) str.size(); i++) {
            assert(P[a + i] == str[i] || P[a + i] == '?');
            P[a + i] = str[i];
        }
    }

    return k;
}

void finish_string() {
    cerr << "finish_string" << endl;
    int start = -1;

    for (int i = 0; i < N - 1; i++)
        if (P[i] != '?' && P[i + 1] != '?')
            start = i;

    assert(start >= 0);
    int end = start;

    while (end < N && P[end] != '?')
        end++;

    for (int i = end; i < N; i++)
        if (P[i] == '?') {
            query(P.substr(start, i - start) + 'C');
            query(P.substr(start, i - start) + 'H');

            if (P[i] == '?')
                P[i] = 'O';
        }

    for (int i = start - 1; i >= 0; i--)
        if (P[i] == '?') {
            query('C' + P.substr(i + 1));
            query('H' + P.substr(i + 1));

            if (P[i] == '?')
                P[i] = 'O';
        }

    answer();
}

void finish_with_candidates(vector<string> candidates) {
    for (string candidate : candidates)
        assert((int) candidate.size() == N);

    for (int i = 0; i < (int) candidates.size() - 1; i++)
        if (query(candidates[i]) > 0) {
            answer();
            return;
        }

    P = candidates.back();
    answer();
}

void solve_case() {
    cin >> N;
    P = string(N, '?');

    if (query("CO") > 0) {
        finish_string();
        return;
    }

    if (query("CH") > 0) {
        finish_string();
        return;
    }

    if (query("OH") + query("HO") > 0) {
        int start = N;

        while (start > 0 && P[start - 1] == '?')
            start--;

        assert(start > 0);

        for (int i = 0; i < start; i++)
            if (P[i] == '?') {
                if (i > 0) {
                    P[i] = P[i - 1];
                    continue;
                }

                for (int j = i; j < N; j++)
                    if (P[j] != '?') {
                        P[i] = P[j];
                        break;
                    }
            }

        char previous = P[start - 1];
        vector<string> candidates;

        for (int first_c = start; first_c <= N; first_c++) {
            string candidate = P;

            for (int i = start; i < N; i++)
                if (i < first_c)
                    candidate[i] = previous;
                else
                    candidate[i] = 'C';

            candidates.push_back(candidate);
        }

        finish_with_candidates(candidates);
        return;
    }

    if (query("CCC") > 0) {
        int prefix = count(P.begin(), P.end(), '?');
        vector<string> candidates;
        candidates.push_back(string(prefix, 'O') + P.substr(prefix));
        candidates.push_back(string(prefix, 'H') + P.substr(prefix));
        finish_with_candidates(candidates);
        return;
    }

    if (query("OOC") > 0) {
        char current = 'O';

        for (int i = 0; i < N; i++)
            if (P[i] == '?')
                P[i] = current;
            else
                current = 'C';

        answer();
        return;
    }

    if (query("HHC") > 0) {
        char current = 'H';

        for (int i = 0; i < N; i++)
            if (P[i] == '?')
                P[i] = current;
            else
                current = 'C';

        answer();
        return;
    }

    vector<string> candidates;
    candidates.push_back(string(N, 'O'));
    candidates.push_back(string(N, 'H'));
    finish_with_candidates(candidates);
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}
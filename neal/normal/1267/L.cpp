#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET = 26;

int N, L, K;
int freq[ALPHABET], freq_copy[ALPHABET];

bool possible(string prefix) {
    memcpy(freq_copy, freq, sizeof(freq));

    for (char c : prefix)
        freq[c - 'a']--;

    for (int a = 0; a < ALPHABET; a++)
        if (freq[a] < 0) {
            memcpy(freq, freq_copy, sizeof(freq));
            return false;
        }

    int remaining = K;
    bool answer = true;

    for (int i = 0; i < (int) prefix.size(); i++) {
        int current = prefix[i] - 'a';
        int sum = 0;

        for (int a = 0; a < current; a++)
            sum += freq[a];

        if (sum >= remaining) {
            answer = true;
            break;
        }

        remaining -= sum;

        if (remaining > freq[current]) {
            answer = false;
            break;
        }

        for (int a = 0; a < current; a++)
            freq[a] = 0;

        freq[current] -= remaining;
    }

    memcpy(freq, freq_copy, sizeof(freq));
    return answer;
}

vector<string> build(string answer) {
    vector<string> output(N, string(L, '.'));
    output[K] = answer;

    for (char c : answer)
        freq[c - 'a']--;

    int remaining = K;

    for (int i = 0; i < (int) answer.size(); i++) {
        int current = answer[i] - 'a';

        for (int a = 0; a < current; a++)
            while (remaining > 0 && freq[a] > 0) {
                remaining--;
                freq[a]--;
                output[remaining][i] = a + 'a';
            }

        if (remaining <= 0)
            break;

        for (int r = 0; r < remaining; r++) {
            output[r][i] = current + 'a';
            freq[current]--;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < L; j++)
            if (output[i][j] == '.') {
                for (int c = 0; c < ALPHABET; c++)
                    if (freq[c] > 0) {
                        output[i][j] = c + 'a';
                        freq[c]--;
                        break;
                    }
            }

    sort(output.begin(), output.end());
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> L >> K;
    K--;

    string str;
    cin >> str;

    for (char c : str)
        freq[c - 'a']++;

    string answer = "";

    for (int index = 0; index < L; index++) {
        answer += 'a';

        for (char c = 'a'; c <= 'z'; c++) {
            answer.back() = c;

            if (possible(answer))
                break;
        }
    }

    // cerr << "answer = " << answer << endl;
    vector<string> output = build(answer);

    for (string &s : output)
        cout << s << '\n';
}
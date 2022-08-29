#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const long long FLY = 1, SWIM = 3, WALK = 5;

int N;
vector<long long> lengths;
string segments;

vector<long long> walked;
vector<long long> swam;
vector<long long> stamina_change;
long long total, stamina;
int first_walk, first_swim;

void walk(int index, long long length) {
    total += WALK * length;
    stamina += length;
    stamina_change[index] += length;
    walked[index] += length;

    if (first_walk == -1 || index < first_walk)
        first_walk = index;
}

void swim(int index, long long length) {
    total += SWIM * length;
    stamina += length;
    stamina_change[index] += length;
    swam[index] += length;

    if (first_swim == -1 || index < first_swim)
        first_swim = index;
}

void fly(int index, long long length) {
    assert(stamina >= length);
    total += FLY * length;
    stamina -= length;
    stamina_change[index] -= length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    lengths.resize(N);

    for (long long &len : lengths)
        cin >> len;

    cin >> segments;

    walked.assign(N, 0);
    swam.assign(N, 0);
    stamina_change.assign(N, 0);

    total = stamina = 0;
    first_walk = first_swim = -1;

    for (int i = 0; i < N; i++) {
        char terrain = segments[i];
        long long length = lengths[i];

        if (terrain == 'G') {
            walk(i, length);
        } else if (terrain == 'W') {
            swim(i, length);
        } else if (terrain == 'L') {
            if (stamina < length) {
                long long need = length - stamina;

                if (first_swim >= 0)
                    swim(first_swim, need);
                else
                    walk(first_walk, need);
            }

            fly(i, length);
        } else {
            assert(false);
        }
    }

    vector<long long> ending_stamina(N, 0);
    long long stamina_sum = 0;

    for (int i = 0; i < N; i++) {
        stamina_sum += stamina_change[i];
        ending_stamina[i] = stamina_sum;
    }

    // First remove walks.
    long long min_stamina = ending_stamina.back();

    for (int i = N - 1; i >= 0; i--) {
        min_stamina = min(min_stamina, ending_stamina[i]);
        long long remove_walk_doubled = min(min_stamina, 2 * walked[i]);
        total -= remove_walk_doubled * (WALK - FLY) / 2;
        min_stamina -= remove_walk_doubled;
        stamina_change[i] -= remove_walk_doubled;
    }

    // Recompute ending_stamina.
    stamina_sum = 0;

    for (int i = 0; i < N; i++) {
        stamina_sum += stamina_change[i];
        ending_stamina[i] = stamina_sum;
    }

    // Now remove swims.
    min_stamina = ending_stamina.back();

    for (int i = N - 1; i >= 0; i--) {
        min_stamina = min(min_stamina, ending_stamina[i]);
        long long remove_swim_doubled = min(min_stamina, 2 * swam[i]);
        total -= remove_swim_doubled * (SWIM - FLY) / 2;
        min_stamina -= remove_swim_doubled;
        stamina_change[i] -= remove_swim_doubled;
    }

    cout << total << '\n';
}
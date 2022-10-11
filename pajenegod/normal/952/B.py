import sys
seen_cool = False
no_counter = 0

normal = ['great','bad','think','touch','cool']

for i in range(10):
    print(i)
    sys.stdout.flush()
    s = input()
    if s=='no':
        no_counter += 1
        if no_counter>3:
            print('normal')
            break
    else:
        found = False
        for f in normal:
            if f in s:
                found = True
        if found:
            print('normal')
        else:
            print('grumpy')
        break
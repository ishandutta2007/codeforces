# ./a-whose-sentence-is-it.yml
idk = 'OMG>.< I don\'t know!'
for _ in range(int(input())):
    ln = input()
    a = ln.startswith('miao.')
    b = ln.endswith('lala.')
    if a != b:
        if a:
            print('Rainbow\'s')
        else:
            print('Freda\'s')
    else:
        print(idk)
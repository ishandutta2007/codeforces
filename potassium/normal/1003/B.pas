program Codeforces;

var
    i,j            : longint;

    max            : longint;

    cnt            : array[0..1] of longint;
    cur            : longint;
    x              : longint;

begin
     readln(cnt[0],cnt[1],x);

     if cnt[0] > cnt[1]
     then max := 0
     else max := 1;

     for i := 1 to x-1 do
     begin
          if (i mod 2 = 1)
          then begin
                    write(max);
                    dec(cnt[max]);
                    dec(x);
                    cur := max;
               end
          else begin
                    write(max XOR 1);
                    dec(cnt[max XOR 1]);
                    dec(x);
                    cur := max XOR 1;
               end;
     end;

     for i := 1 to cnt[cur XOR 1] do
         write(cur XOR 1);

     for i := 1 to cnt[cur] do
         write(cur);

     readln;
end.
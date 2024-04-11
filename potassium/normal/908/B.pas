program BuggyBot;

var n,m,i,j,k,l  : longint;
    st           : array[1..2] of longint;
    x,y          : longint;
    a            : array[1..50,1..50] of char;
    s            : string;
    cnt          : longint;

procedure decode(num : longint);

begin
     if num = 1
     then dec(y);
     if num = 2
     then inc(x);
     if num = 3
     then inc(y);
     if num = 4
     then dec(x);
end;

begin
     readln(n,m);

     for i := 1 to n do
     begin
          for j := 1 to m do
          begin
               read(a[i,j]);

               if a[i,j] = 'S'
               then begin
                         st[1] := i;
                         st[2] := j;
                    end;
          end;

          readln;
     end;

     readln(s);

     cnt := 0;

     for i := 1 to 4 do
     begin
          for j := 1 to 4 do
          begin
               if j <> i
               then for k := 1 to 4 do
                    begin
                         if (k <> i) AND (k <> j)
                         then begin
                                   y := st[1];
                                   x := st[2];

                                   for l := 1 to length(s) do
                                   begin
                                        if s[l] = '0'
                                        then decode(i);
                                        if s[l] = '1'
                                        then decode(j);
                                        if s[l] = '2'
                                        then decode(k);
                                        if s[l] = '3'
                                        then decode(10-i-j-k);

                                        if (x < 1) OR (x > m) OR (y < 1) OR (y > n) OR (a[y,x] = '#')
                                        then break;

                                        if a[y,x] = 'E'
                                        then begin
                                                  inc(cnt);
                                                  break;
                                             end;
                                   end;
                              end;
                    end;
          end;
     end;

     writeln(cnt);
end.
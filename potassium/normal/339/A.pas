var s            : ansistring;
    i            : longint;
    x            : longint;
    b            : boolean;
    cnt          : array[1..3] of longint;


begin
     readln(s);

     for i := 1 to length(s) do
         if i mod 2 = 1
         then begin
                   val(s[i],x);
                   inc(cnt[x]);
              end;

     b := FALSE;

     for i := 1 to cnt[1] do
     begin
          if b
          then write('+');

          write(1);
          b := TRUE;
     end;

     for i := 1 to cnt[2] do
     begin
          if b
          then write('+');

          write(2);
          b := TRUE;
     end;

     for i := 1 to cnt[3] do
     begin
          if b
          then write('+');

          write(3);
          b := TRUE;
     end;
end.
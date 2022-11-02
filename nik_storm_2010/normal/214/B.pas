var
    a:array[0..9] of longint; m1,m2,x,j,kol1,kol2,i,n,sum:longint;


begin

  readln(n);
  for i:=1 to n do
    begin
      read(x); inc(a[x]);
        if x mod 3=1 then inc(kol1);
        if x mod 3=2 then inc(kol2);
      inc(sum,x);
    end;

  if a[0]=0 then begin writeln(-1); halt; end;
    if (sum mod 3=0) then
      begin
        m1:=0; m2:=0;
      end
        else
      begin
        if (sum mod 3=1) then
          begin
            if kol1<>0 then begin m1:=1; m2:=0; end
                else
                begin
                  if kol2>=2 then begin m1:=0; m2:=2; end
                    else
                    begin
                      writeln(-1);
                      halt;
                    end;
                end;
          end
            else
          begin
            if kol2<>0 then begin m1:=0; m2:=1; end
              else
              begin
                if kol1>=2 then begin m1:=2; m2:=0; end
                  else
                  begin
                    writeln(-1);
                    halt;
                  end;
              end;
          end;
      end;

  sum:=0;
  for i:=1 to 9 do
    begin
      while (i mod 3=1) and (m1>0) and (a[i]>0) do begin dec(m1); dec(a[i]); end;
      while (i mod 3=2) and (m2>0) and (a[i]>0) do begin dec(m2); dec(a[i]); end;
      sum:=sum+a[i];
    end;
  if sum=0 then begin writeln(0); halt; end
    else
    begin
      for i:=9 downto 0 do
        for j:=1 to a[i] do
      write(i);
    end;

end.
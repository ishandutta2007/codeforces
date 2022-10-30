var
    a,c:array[1..100] of longint; leng,ans,tek,n,i:longint;


begin

  readln(n); for i:=1 to n do read(a[i]); ans:=0;
  for i:=1 to n do
    begin
      if a[i]<0 then
        begin
          inc(tek); if tek<>3 then inc(leng) else
            begin
              inc(ans); c[ans]:=leng;
              tek:=1; leng:=1;
            end;
        end
        else inc(leng);
    end;
  if leng<>0 then begin inc(ans); c[ans]:=leng; end;
  writeln(ans); for i:=1 to ans do write(c[i],' ');

end.
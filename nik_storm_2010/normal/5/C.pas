var
    stack:array[0..1000000] of char; k:array[0..1000000] of longint;
      leng,open,clos,ans,kol,d,i:longint; s:ansistring;


procedure addtostack(c:char);
begin
  if c=')' then
    begin
      if stack[leng]='(' then
        begin
          k[leng-1]:=k[leng-1]+k[leng]+1; dec(leng);
          if k[leng]*2>ans then begin ans:=k[leng]*2; kol:=1; end
            else if k[leng]*2=ans then inc(kol);
        end
          else
        begin
          leng:=0; k[0]:=0;
        end;
    end
      else
    begin
      inc(leng); stack[leng]:='('; k[leng]:=0;
    end;
end;


begin

  readln(s); d:=length(s); ans:=0; kol:=1;
  for i:=1 to d do
  addtostack(s[i]);
  writeln(ans,' ',kol);

end.
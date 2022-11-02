var
  l,r:array[1..1000000] of longint; t,x,y,n,m,s,f,i:longint;


begin
  readln(n,m,s,f);
  for i:=1 to m do
  begin
    readln(t,x,y);
    if (t>1000000) then continue else
    begin
      l[t]:=x;
      r[t]:=y;
    end;
  end;
  for i:=1 to 1000000 do
  begin
    if (s=f) then halt;
    if (l[i]=0) then
    begin
      if (s<f) then begin write('R'); inc(s); end else begin write('L'); dec(s); end;
    end
      else
    begin
      if (s<f) then
      begin
        if (not((l[i]<=s) and (s<=r[i]))) and (not((l[i]<=s+1) and (s+1<=r[i]))) then
        begin
          write('R');
          inc(s);
        end
        else write('X');
      end
        else
      begin
        if (not((l[i]<=s) and (s<=r[i]))) and (not((l[i]<=s-1) and (s-1<=r[i]))) then
        begin
          write('L');
          dec(s);
        end
        else write('X');
      end;
    end;
  end;
end.
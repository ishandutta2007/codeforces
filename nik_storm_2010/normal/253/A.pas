var
    n,m,i:longint;


procedure inputdata;
begin
  assign(input,'input.txt'); reset(input);
  readln(n,m);
  close(input);
end;

begin

  inputdata;
  assign(output,'output.txt'); rewrite(output);
  if n>=m then
    begin
      while (n>0) and (m>0) do
        begin
          write('BG');
          dec(n); dec(m);
        end;
      for i:=1 to n do write('B');
    end
      else
    begin
      while (n>0) and (m>0) do
        begin
          write('GB');
          dec(n); dec(m);
        end;
      for i:=1 to m do write('G');
    end;
  close(output);

end.
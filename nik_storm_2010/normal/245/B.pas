var
    d,i,j:longint; s:string;


begin

  readln(s); d:=length(s);
  if s[1]='f' then begin write('ftp://'); j:=3; end
              else begin write('http://'); j:=4; end;

  for i:=d downto 1 do
    if (s[i]='u') and (s[i-1]='r') then
      begin
        if i=d then
          begin
            write(copy(s,j+1,i-j-2),'.ru');
          end
            else
          begin
            write(copy(s,j+1,i-j-2),'.ru/',copy(s,i+1,d-i+1));
          end;
        halt;
      end;

end.
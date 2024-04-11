var
    pred,s,snew:ansistring; i,d:longint; c:char;


procedure first(var sim:char);
  var i:longint;
begin
  sim:=chr(200);
  for i:=1 to d do
    if s[i]<>' ' then
      begin
        sim:=s[i];
        break;
      end;
end;


begin

  pred:='no string';
  while not(eof) do
    begin
      readln(s); d:=length(s); first(c);
      if c='#' then
        begin
          if pred = 'no string' then write(s) else
            begin
              writeln; write(s);
            end;
          pred:='increas';
        end
          else
        begin
          snew:=''; for i:=1 to d do if s[i]<>' ' then snew:=snew+s[i];
          if pred = 'no string' then
            begin
              write(snew);
            end
              else
            begin
              if pred = 'increas' then
                begin
                  writeln; write(snew);
                end
                  else
                begin
                  write(snew);
                end;
            end;
          pred:='normal';
        end;
    end;
  writeln;

end.